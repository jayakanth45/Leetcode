# Write your MySQL query statement below
select d.name as Department,e.name as Employee,e.salary from Employee e
JOIN Department d on e.departmentId=d.id where (e.departmentId,e.salary) IN (select departmentId,max(salary) from Employee group by departmentId);
