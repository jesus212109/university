//Ej 4 
//Para borrar una tabla debes de borrar antes las tablas que referencian a esta

//  Ej 5
insert into votantes 
values(30653845, 'Maria Gonzales Ramirez', 'Doctorado', 'Activo', 'goram@telefonica.es', 1, '21/08/1989', 677544822);

select *
from votantes;

delete from votantes 
where dni = 30653845;

//Ej 9
select nombre, tipo, fecha
from eventos;

//Ej 10
select nombre||' de tipo ' ||tipo "Convocatoria"
from eventos;

