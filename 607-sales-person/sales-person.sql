# Write your MySQL query statement belo
select name
from SalesPerson
where sales_id not in (
    select sales_id
    from Orders od
    join Company cp
    on od.com_id=cp.com_id
    where name = 'RED'
);