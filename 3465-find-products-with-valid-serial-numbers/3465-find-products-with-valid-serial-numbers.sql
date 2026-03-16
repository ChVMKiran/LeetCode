SELECT *
FROM products
WHERE description REGEXP '(^| )SN[0-9]{4}-[0-9]{4}([^0-9A-Z]|$)'
AND description LIKE BINARY '%SN%'
ORDER BY product_id;