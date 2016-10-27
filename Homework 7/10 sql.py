# Open the database
import sqlite3
connection = sqlite3.connect('mcu.db')
# Display the all customers
cursor = connection.cursor()
cursor.execute("insert into characters values(100, 'Luis' )");
cursor.execute("insert into teamUps values(100, 38, 12)");
cursor.execute(" SELECT distinct characters.name from characters, fights, teamUps where (member1 = characters.id or member2 = characters.id or combatant1 = characters.id or combatant2 = characters.id) and characters.name like 'L%' ") 
for row in cursor:
    print(row) 
