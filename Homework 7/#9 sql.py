# Open the database
import sqlite3
connection = sqlite3.connect('mcu.db')
# Display the all customers
cursor = connection.cursor()
cursor.execute("SELECT distinct characters.name from characters, teamUps where characters.name = 'Howard Stark' and member1 = characters.id or member2 = characters.id intersect SELECT distinct characters.name from characters, teamUps where characters.name = 'Peggy Carter' and member1 = characters.id or member2 = characters.id ")
for row in cursor:
    print(row)    
