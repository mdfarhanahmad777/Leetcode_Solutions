# Write your MySQL query statement below
# Write your MySQL query statement below
select emp.name AS Employee from Employee as emp
JOIN Employee as mngr on emp.managerId = mngr.id
where emp.salary > mngr.salary;