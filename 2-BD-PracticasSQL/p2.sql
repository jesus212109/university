select v.nombrecompleto, lo.nombre
from votantes v, localidades lo
where v.localidad = lo.idlocalidad;

//Ej 1

select nombrecompleto
from votantes
where nombrecompleto like '%n';     //Aqui si es key-sensitive

//Ej 2

select dni  
from votantes
where dni like '%5%5%5%';

//Ej 3

select nombrecompleto
from votantes
where fechanacimiento > '1/1/90';

//Ej 4

select v.nombrecompleto, lo.nombre
from votantes v, localidades lo
where v.localidad = lo.idlocalidad and lo.numerohabitantes > 300000;

//Ej 5

select v.nombrecompleto, p.comunidad
from votantes v, localidades lo, provincias p
where v.localidad = lo.idlocalidad and lo.provincia = p.idprovincia and lo.numerohabitantes > 300000;

//Ej 6 y 7

select c.partido, count(c.partido) "conteo"
from consultas_datos c
group by c.partido ; 

//Ej 8

select p.nombrecompleto
from partidos p, consultas_datos c
where p.idpartido = c.partido
group by p.nombrecompleto
having count(c.partido) > 10;

//Ej 9

select p.nombrecompleto , count(c.partido)
from partidos p, consultas_datos c
where p.idpartido = c.partido
group by p.nombrecompleto
having count(c.partido) > 10;

//Ej 10

select p.nombrecompleto , count(c.certidumbre) "conteo"
from partidos p, consultas_datos c
where p.idpartido = c.partido and c.certidumbre > 0.8 and c.respuesta = 'Si'
group by p.nombrecompleto;



//Practica creación de tabla
create table test(
t1 number(3) primary key,
t2 varchar2(64) not null,
t3 date
);

insert into test
values(1,'No se que poner', '1/1/2000' );

describe test;

drop table test;

//Ampliación 
/*
*/



//1. Obtener el DNI de todos los votantes que tengan dos 6s en su teléfono pero contemplar que no tienen más de tres
select dni
from votantes
where dni like '%6%6%' and not dni like '%6%6%6%' ;

//2. Obtener el DNI de todos los votantes que tengan tres 6s en su teléfono pero contemplar que no tienen más de tres, dos de ellos deben estar juntos
select dni
from votantes
where dni like '%6%66%' or dni like '%66%6%' and not dni like '%6%6%6%6%';

//3. Mostrar aquella localidad cuyo número de habitantes acaba igual que su número de provincia, mostrando también el nombre de la provincia a la que pertenece
select l.nombre
from localidades l
where l.provincia = substr(l.numerohabitantes, -1);


--4. Mostrar el nombre completo de los votantes cuyo teléfono acaba igual que su dni
select v.nombrecompleto
from votantes v
where substr(v.dni, -1) = substr(v.telefono, -1);

--5. Mostrar el nombre completo de aquellos votantes que contienen al menos una 'S' y cuya fecha de nacimiento es anterior al 12 de Febrero de 1990.
select nombrecompleto
from votantes
where nombrecompleto like '%S%' and fechanacimiento > '12/02/1990';

--6. Usar el operador DISTINCT (http://www.w3schools.com/sql/sql_distinct.asp). Obtener todos los votantes que han participado en alguna consulta. Dichos votantes deben aparecer en orden decreciente de dni
select distinct votante
from consultas
order by votante desc;

--7. Mostrar el dni de aquellos votantes que han participado en más de tres consultas 
select votante
from consultas
having count(votante) > 3
group by votante;

--8. Mostrar el nombre completo de los votantes que han participado en más de tres consultas y especificar en cuántas consultas participaron  (en orden creciente)
select v.nombrecompleto, count (c.votante)
from votantes v, consultas c
where v.dni = c.votante
group by c.votante, v.nombrecompleto
having count(c.votante) > 3 
order by count(c.votante);

--9. Obtener el nombre de los votantes y el nombre de su localidad para aquellos votantes que han sido consultados en una localidad que tiene más de 300000 habitantes
select v.nombrecompleto, l.nombre
from votantes v, localidades l
where v.localidad = l.idlocalidad and l.numerohabitantes > 300000;

--10. Mostrar el nombre de cada partido político y la máxima certidumbre que tiene para sus consultas
select p.nombrecompleto, max(c.certidumbre)
from partidos p, consultas_datos c
where p.idpartido = c.partido
group by p.nombrecompleto;

--11. Mostrar el nombre del votante y su certidumbre media en todas las consultas en las que ha respondido de manera afirmativa
select v.nombrecompleto, avg(cd.certidumbre)
from votantes v, consultas_datos cd, consultas c
where v.dni = c.votante and c.idconsulta = cd.consulta and cd.respuesta like 'Si'
group by v.nombrecompleto;

--12. Mostrar el nombre del votante y su certidumbre media en todas las consultas en las que ha respondido de manera afirmativa ÚNICAMENTE para aquellos votantes cuyo certidumbre media esté entre 0'5 y 0'8.
select v.nombrecompleto, avg(cd.certidumbre)
from votantes v, consultas_datos cd, consultas c
where v.dni = c.votante and c.idconsulta = cd.consulta and cd.respuesta like 'Si'
having avg(cd.certidumbre) > 0.5 and avg(cd.certidumbre) < 0.8
group by v.nombrecompleto;

--13. Mostrar el nombre de los partidos y la certidumbre media obtenida para cada partido considerando sólo aquellas consultas en las que el encuestado ha contestado negativamente a votar a dicho partido y con una certidumbre significativa (por encima del 60%)
select p.nombrecompleto, avg(c.certidumbre)
from partidos p, consultas_datos c
where p.idpartido = c.partido and c.respuesta like 'No'
having avg(c.certidumbre) > 0.6
group by p.nombrecompleto;