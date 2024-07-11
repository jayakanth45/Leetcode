# Write your MySQL query statement below
select P.product_id , ifnull(round((sum(P.price * U.units)/sum(units)) , 2),0) as average_price 
from Prices as P left join UnitsSold as U 
on P.product_id = U.product_id 
AND u.purchase_date BETWEEN start_date AND end_date
group by product_id ;