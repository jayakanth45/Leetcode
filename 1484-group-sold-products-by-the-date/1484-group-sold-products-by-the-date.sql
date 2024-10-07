# Write your MySQL query statement below
select s.sell_date,count(distinct product) as num_sold,GROUP_CONCAT(distinct product ORDER BY product ASC SEPARATOR ',') AS products from Activities s
group by(s.sell_date) order by s.sell_date ASC;
