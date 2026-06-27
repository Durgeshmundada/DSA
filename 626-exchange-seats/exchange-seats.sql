select 
    case 
      when id%2=1 AND id!=(SELECT MAX(id) FROM Seat) then id+1
      when id%2=0 then id-1
      else id
      END as id,student
from seat 
order by id;