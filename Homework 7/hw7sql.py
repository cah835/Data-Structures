
import sqlite3
connection = sqlite3.connect('mcu.db')
# Display the all customers
cursor = connection.cursor()
cursor.execute("create temporary table appearences as SELECT distinct characters.name as cname, movie from characters, fights where combatant1 = characters.id or combatant2 = characters.id union SELECT distinct characters.name as cname, movie from characters, teamUps where member1 = characters.id or member2 = characters.id group by cname, movie ")
cursor.execute("SELECT MAX(cc), cname from (SELECT count(*) as cc, cname from appearences group by cname)")
cursor.execute("SELECT * from appearences")
for row in cursor:
    print(row)

    # this is #8
'''
# Open the database
import sqlite3

connection = sqlite3.connect('mcu.db')

# Display the all customers

cursor = connection.cursor()

cursor.execute("SELECT MAX(cc), combatant1, combatant2, name from(SELECT count(*) as cc, combatant1, combatant2, group_concat(movies.name) as name from fights, movies where movies.id = fights.movie group by combatant1, combatant2)")

for row in cursor:

    print(row)


# prints out nick fury movies

# Open the database

import sqlite3

connection = sqlite3.connect('mcu.db')

# Display the all customers

cursor = connection.cursor()

cursor.execute("SELECT distinct movies.name from movies, characters, fights, teamUps where(combatant1 = characters.id or combatant2 = characters.id or member1 = characters.id or member2 = characters.id) and characters.name = 'Nick Fury'") 
for row in cursor:

    print(row)

# Open the database

import sqlite3

connection = sqlite3.connect('mcu.db')

# Display the all customers

cursor = connection.cursor()

cursor.execute("SELECT MAX(cc), member1, member2 from (SELECT count(*) as cc, member1, member2 from teamUps group by member1, member2)") 
for row in cursor:

    print(row)


#Open the database
import sqlite3
connection = sqlite3.connect('mcu.db')
# Display the all customers
cursor = connection.cursor()
cursor.execute("SELECT distinct characters.name from characters, fights, movies, teamups where (member1 = characters.id or member2 = characters.id or combatant1= characters.id or combatant2 = characters.id) and fights.movie = movies.id and teamUps.movie = movies.id and movies.name = 'Iron Man 2'" )
for row in cursor:

    print(row)

'''
