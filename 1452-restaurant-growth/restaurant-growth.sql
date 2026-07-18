select visited_on,amount,round(amount/7,2) as average_amount
from (
SELECT
    c.visited_on,
    (
        SELECT SUM(amount)
        FROM Customer
        WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY)
                            AND c.visited_on
    ) AS amount
FROM Customer c
WHERE c.visited_on >= (
    SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
    FROM Customer
)
group by visited_on)t;