# Write your MySQL query statement below
SELECT Department.name as 'Department', Employee.name as 'Employee', Salary FROM Employee JOIN Department on Employee.departmentId = Department.id
WHERE (Employee.departmentID, salary) in ( SELECT DepartmentID , MAX(salary) FROM Employee Group BY DepartmentId );