# Write your MySQL query statement below
SELECT firstName, lastName,city, state FROM Person left outer join Address
on (person.personId= Address.personId)