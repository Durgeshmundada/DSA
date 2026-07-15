SELECT product_id, new_price AS price
FROM Products p
WHERE change_date = (
    SELECT MAX(change_date)
    FROM Products ps
    WHERE ps.product_id = p.product_id
      AND ps.change_date <= '2019-08-16'
)
union
SELECT product_id, 10 AS price
FROM Products
GROUP BY product_id
HAVING MIN(change_date) > '2019-08-16';