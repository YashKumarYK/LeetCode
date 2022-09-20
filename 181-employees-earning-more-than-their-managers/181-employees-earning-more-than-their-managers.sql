# Write your MySQL query statement below
SELECT E1.name as Employee from Employee as E1, Employee as E2 WHERE E1.managerid = E2.id AND E1.salary > E2.salary  