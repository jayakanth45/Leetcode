# Write your MySQL query statement below
SELECT s.name
FROM Orders AS o
INNER JOIN Company AS c ON c.com_id = o.com_id AND c.name = 'RED'
RIGHT JOIN SalesPerson AS s ON s.sales_id = o.sales_id
WHERE c.name IS NULL;
