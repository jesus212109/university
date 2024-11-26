--1
select nombrecompleto
from votantes
where substr(dni,-1) = (localidad +1);

--2
SELECT v.nombrecompleto, decode(l.nombre,'Cordoba','Madrid','Montilla','Madrid','Baena','Madrid',l.nombre)
FROM votantes v, localidades l
where v.localidad = l.idlocalidad;

--3
select p.siglas
from partidos p, consultas_datos c
where p.idpartido = c.partido 
having count (c.partido) >= all
(
select count(c.partido) 
from consultas_datos c, partidos p 
where p.idpartido = c.partido 
group by c.partido
)
group by c.partido, p.siglas;

--4    CAE MUCHO EN EXÁMENES
select v.dni
from votantes v
where v.fechanacimiento =  --sea igual al resultado para que solo se imprima este por pantalla
(
    select min(v.fechanacimiento)
    from votantes v
    where v.fechanacimiento != 
    (
        select min(v.fechanacimiento) 
        from votantes v
    )
--selecciono la fecha mínima tras haber excluido la más minima con anterioridad = escojo la segunda más pequeña
);

--5
select votante, count(votante)
from consultas
group by votante
order by count(votante) desc;

--6
select votante, count(votante)
from consultas
group by votante
having count(votante) > 
(
select AVG(count(votante))
from consultas
group by votante
)
order by count(votante) desc;

--7
select v.nombrecompleto
from consultas c, votantes v
where v.dni = c.votante
group by v.nombrecompleto, c.votante
having count(votante) > 
(
    select AVG(count(votante))
    from consultas c, votantes v
    where v.dni = c.votante
    group by c.votante, v.nombrecompleto
)
;

--8
select votante, count(votante)
from consultas c, votantes v
where v.dni = c.votante and v.dni != 
(
    select v.dni
    from votantes v
    where v.fechanacimiento =  --sea igual al resultado para que solo se imprima este por pantalla
    (
        select min(v.fechanacimiento)
        from votantes v
        where v.fechanacimiento != (select min(v.fechanacimiento) from votantes v)
    )
)
group by c.votante
order by count(votante) desc;

--EJERCICIOS ADICIONALES
--1
SELECT SUBSTR(nombrecompleto,1,INSTR(nombrecompleto,' ')) "Nombre", l.nombre "Localidad", p.comunidad "Comunidad Autónoma"
from votantes v, localidades l, provincias p
where v.localidad = l.idlocalidad and p.idprovincia = l.provincia and l.idlocalidad in ( 1, 3, 9)
;

--2
--OJO EN FROM PONER DOS VECES LA MISMA TABLA CON DISTINTOS ALIAS 
--Y RELACCIONARLO PARA QUE CUMPLA UNA CONDICIÓN
--(LOCALIDAD)
select a.nombre ||' va antes que ' || b.nombre "Ordenación"
from localidades a, localidades b
where a.idlocalidad = b.idlocalidad - 1;

--3
select l.nombre
from localidades l
where l.numerohabitantes >
(
    select l.numerohabitantes
    from localidades l, votantes v
    where v.localidad = l.idlocalidad and v.dni = 
    (
        select v.dni
        from votantes v
        where v.fechanacimiento =  --sea igual al resultado para que solo se imprima este por pantalla
        (
            select min(v.fechanacimiento)
            from votantes v
            where v.fechanacimiento != (select min(v.fechanacimiento) from votantes v)
        )
    )
);

/* --SUBRUTINA QUE OBTIENE EL NUMERO DE HABITANTES DE LA LOCALIDAD DE EL SEGUNDO VOTANTE 
   --CON MAS EDAD ENTRE TODOS LOS EXISTENTES

select l.numerohabitantes
from localidades l, votantes v
where v.localidad = l.idlocalidad and v.dni = 
(
    select v.dni
        from votantes v
        where v.fechanacimiento =  --sea igual al resultado para que solo se imprima este por pantalla
        (
            select min(v.fechanacimiento)
            from votantes v
            where v.fechanacimiento != (select min(v.fechanacimiento) from votantes v)
        )
    );
*/


--Incompleto
--4  Con decode mas resta de funcion que dice la fecha de hoy 
select v.nombrecompleto, v.localidad
from votantes v
where v.localidad in(2, 4, 8)
;

--5
select l.nombre, l.numerohabitantes, p.comunidad
from localidades l, provincias p
where p.idprovincia = l.provincia and l.provincia in( 1, 2, 3) and l.numerohabitantes > 
any( 
    select l.numerohabitantes
    from localidades l
    where l.provincia = 4
    )
;

--6
select v.nombrecompleto
from consultas c, votantes v
where v.dni = c.votante and v.situacionlaboral = 'Activo'
group by v.nombrecompleto, c.votante
having count(votante) < 
(
    select AVG(count(votante))
    from consultas c, votantes v
    where v.dni = c.votante
    group by c.votante, v.nombrecompleto
)
;

--7
select l.nombre, avg(decode( v.estudiossuperiores, 'Ninguno', 0 , 'Basicos', 1, 'Superiores', 2, 'Doctorado', 3))
from localidades l, votantes v
where l.idlocalidad = v. localidad
group by l.nombre
order by avg(decode( v.estudiossuperiores, 'Ninguno', 0 , 'Basicos', 1, 'Superiores', 2, 'Doctorado', 3)) desc;

