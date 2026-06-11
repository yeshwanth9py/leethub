-- Last updated: 6/11/2026, 11:27:44 AM
select euni.unique_id, em.name
from Employees as em left join EmployeeUNI as euni on em.id=euni.id;


-- COALESCE