# Write your MySQL query statement below
SELECT
*
FROM
USERS
WHERE
EMAIL REGEXP '^[a-z0-9_]+@[^@0-9]+\\.com$'
ORDER BY USER_ID;