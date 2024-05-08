/* Write your T-SQL query statement below */
select product_name, year, price
from Sales S inner join Product P 
on S.product_id = P.product_id
