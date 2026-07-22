# Write your MySQL query statement below
DELETE A
FROM Person A
JOIN Person B
ON A.email=B.email
AND a.id>b.id;