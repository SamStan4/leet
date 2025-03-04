SELECT Customer.name
FROM Customer
WHERE
    Customer.referee_id <> 2 OR Customer.referee_id IS NULL
;

-- or

SELECT Customer.name
FROM Customer
WHERE
    COALESCE(Customer.referee_id, 0) <> 2
;