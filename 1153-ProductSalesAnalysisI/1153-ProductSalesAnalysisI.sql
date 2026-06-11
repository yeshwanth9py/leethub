-- Last updated: 6/11/2026, 11:29:29 AM
select p.product_name, s.year, s.price
from Sales as s join Product as p on p.product_id = s.product_id;
