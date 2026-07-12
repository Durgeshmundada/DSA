# Write your MySQL query statement below
SELECT P.product_name,S.year,s.price
from sales as s
join product as p
on s.product_id=p.product_id;