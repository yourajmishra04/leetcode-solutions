# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary
FROM (
    SELECT salary ,
    DENSE_RANK()  OVER (ORDER BY salary DESC ) r
    FROM Employee 
)t
WHERE r=2;