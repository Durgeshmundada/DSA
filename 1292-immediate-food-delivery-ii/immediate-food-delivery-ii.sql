SELECT
    ROUND(SUM(imm) * 100.0 / COUNT(*), 2) AS immediate_percentage
FROM (
    SELECT
        d.delivery_id,
        CASE
            WHEN order_date = customer_pref_delivery_date THEN 1
            ELSE 0
        END AS imm,order_date
    FROM Delivery d
    where  order_date = (
                     SELECT MIN(order_date)
                     FROM Delivery dl
                     WHERE dl.customer_id = d.customer_id
                 )
) t;
