# Run this script w/ Python to populate the database for assignment 7
# For documentation pysql, see:
#   - Python 3: https://docs.python.org/3/library/sqlite3.html
#   - Python 2: https://docs.python.org/2.7/library/sqlite3.html

import sqlite3
import json

# Open the JSon file and store data for the tables
with open('mcu_raw.json') as mcu_file:
    raw_data = json.load(mcu_file)

names = set()
movies = set()
for datum in raw_data:
    names.add(datum['name1'])
    names.add(datum['name2'])
    movies.add((datum['movie'], datum['release']))
names = list(names)
movies = list(movies) 
movie_names = [movie[0] for movie in movies]   

# Open the database
connection = sqlite3.connect('mcu.db')
cursor = connection.cursor()
cursor.execute('PRAGMA foreign_keys = ON;') # Enable foreign key support
cursor.execute('DROP TABLE IF EXISTS fights;')
cursor.execute('DROP TABLE IF EXISTS teamUps;')
connection.commit()

# Create characters table
cursor.execute('DROP TABLE IF EXISTS characters;')
cursor.execute("""CREATE TABLE characters
(
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL
);""")
cursor.executemany('INSERT INTO characters VALUES (?, ?);', enumerate(names))
connection.commit() 

# Create movies table
cursor = connection.cursor()
cursor.execute('DROP TABLE IF EXISTS movies;')
cursor.execute("""CREATE TABLE movies
(
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    release TEXT NOT NULL
);""")
cursor.executemany('INSERT INTO movies VALUES (?, ?, ?);', 
                  ((i, name, release) for (i, (name, release))
                                      in enumerate(movies)))
connection.commit() 

# Create fought/teamed-up tables
cursor = connection.cursor()
cursor.execute("""CREATE TABLE fights
(
    combatant1 INTEGER NOT NULL,
    combatant2 INTEGER NOT NULL,
    movie INTEGER NOT NULL,
    PRIMARY KEY(combatant1, combatant2, movie),
    FOREIGN KEY(combatant1) REFERENCES characters(id),
    FOREIGN KEY(combatant2) REFERENCES characters(id),
    FOREIGN KEY(movie) REFERENCES movies(id)
);""")
cursor.executemany('INSERT INTO fights VALUES (?, ?, ?);', 
                  ((names.index(datum['name1']),
                    names.index(datum['name2']),
                    movie_names.index(datum['movie']))
                  for datum in raw_data if datum["action"] == "fought"))
                  
cursor.execute("""CREATE TABLE teamUps
(
    member1 INTEGER NOT NULL,
    member2 INTEGER NOT NULL,
    movie INTEGER NOT NULL,
    PRIMARY KEY(member1, member2, movie),
    FOREIGN KEY(member1) REFERENCES characters(id),
    FOREIGN KEY(member2) REFERENCES characters(id),
    FOREIGN KEY(movie) REFERENCES movies(id)
);""")
cursor.executemany('INSERT INTO teamUps VALUES (?, ?, ?);', 
                  ((names.index(datum['name1']),
                    names.index(datum['name2']),
                    movie_names.index(datum['movie']))
                  for datum in raw_data if datum["action"] == "teamedUp"))
connection.commit() 

# All done
connection.close()
