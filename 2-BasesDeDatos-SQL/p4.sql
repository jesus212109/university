--RELACIÓN 1
--Ej1
set serveroutput on
begin
dbms_output.put_line('Hola mundo, hoy es el día ' || sysdate);
end;

--Ej2
set serveroutput on
declare 
nombre votantes.nombrecompleto%type;
correo votantes.email%type;
mydni number := 30983712;
begin
select nombrecompleto,email into nombre , correo from votantes where dni = mydni;
dbms_output.put_line(nombre|| ' con correo ' || correo);
end;

--Ej3
set serveroutput on;
declare 
nombre votantes.nombrecompleto%type;
correo votantes.email%type;
mydni number := 30983712;
begin
select nombrecompleto,email into nombre , correo from votantes where dni = mydni;
dbms_output.put_line(substr(nombre,1, instr(nombre, ' '))|| ' con correo ' || correo);
end;

--Ej4
set serveroutput on;
declare 
nombre votantes.nombrecompleto%type;
mydni number := 30983712;
begin
select decode(nombrecompleto, 'Jose Perez Perez',  'Pepe Perez Perez') into nombre from votantes where dni = mydni;
dbms_output.put_line(nombre);
end;

--Ej5
set serveroutput on;
declare 
nombre votantes.nombrecompleto%type;
mydni votantes.dni%type;
begin
select nombrecompleto, dni into nombre, mydni from votantes where fechanacimiento = (
    select min(fechanacimiento) from votantes
    );
dbms_output.put_line('El señor ' || nombre || ' con el dni ' || mydni || ' es el votante más longevo');
end;

--Ej6
set serveroutput on;
declare 
nombrev votantes.nombrecompleto%type;
nombrej votantes.nombrecompleto%type;
emailv votantes.email%type;
emailj votantes.email%type;
begin
select nombrecompleto into nombrev from votantes where fechanacimiento =  (
    select min(fechanacimiento) from votantes);
select nombrecompleto into nombrej from votantes where fechanacimiento =  (
    select max(fechanacimiento) from votantes);
select decode( email, 'anfernandez@outlook.com', 'anfernandez@uco.es') into emailv from votantes where fechanacimiento = (
    select min(fechanacimiento) from votantes);
select decode( email, 'martita00@hotmail.com', 'martita00@uco.es') into emailj from votantes where fechanacimiento = (
    select max(fechanacimiento) from votantes);
dbms_output.put_line(nombrev || ' -- ' || emailv);
dbms_output.put_line(nombrej || ' -- ' || emailj);
end;

--Ej 7
set serveroutput on;
declare
apellido1 votantes.nombrecompleto%type;
apellido2 votantes.nombrecompleto%type;
begin
select substr(nombrecompleto, 6, 8) into apellido2 from votantes where fechanacimiento = (
    select max(fechanacimiento) from votantes);
select substr(nombrecompleto, 8, 4) into apellido1 from votantes where fechanacimiento = (
    select max(fechanacimiento) from votantes where fechanacimiento <> (
        select max(fechanacimiento) from votantes));
    dbms_output.put_line('El hijo se llama Juan ' || apellido1 || apellido2);
end;

--Ej 8
set serveroutput on;
declare
v_suma_habitantes number;
v_cantidad_localidades number;
begin
select sum(numerohabitantes) into v_suma_habitantes from localidades where idlocalidad in(1, 2);
select count(idlocalidad) into v_cantidad_localidades from localidades where numerohabitantes > v_suma_habitantes;
dbms_output.put_line('Hay ' || v_cantidad_localidades || ' ciudades con mas habitantes de ' || v_suma_habitantes || ' habitantes, que es la suma de las dos localidades con IDs más pequeños');
end;

--RELACIÓN 2  hazla bien coño
--Ej1
set serveroutput on;
DECLARE
CURSOR c IS SELECT * FROM votantes
WHERE substr(dni, -1) = localidad + 1)
BEGIN
FOR num_row IN c LOOP
dbms_output.put_line(num_row.nombrecompleto);
END LOOP;
END;

--Ej 2
set serveroutput on;
DECLARE
CURSOR c IS SELECT * FROM votantes
WHERE substr(dni, -1) = localidad + 1)
votantesData votantes%ROWTYPE;
BEGIN
open c;
LOOP
FETCH c INTO votantesData;
EXIT WHEN c%NOTFOUND;
dbms_output.put_line(votantesData.nombrecompleto);
END LOOP;
END;

--Ej3






--Ej típico EX
select l.nombre, --los paréntesis son necesarios para indicar que es una subconsulta dentro del select
    100*(select count(v.localidad) from votantes where estudiossuperiores = 'Doctorado' and localidad = v.localidad) / count (v.localidad) "Doctorado",
    100*(select count(v.localidad) from votantes where estudiossuperiores = 'Superiores' and localidad = v.localidad) / count (v.localidad) "Superiores",
    100*(select count(v.localidad) from votantes where estudiossuperiores = 'Basicos' and localidad = v.localidad) / count (v.localidad) "Basicos",
    100*(select count(v.localidad) from votantes where estudiossuperiores = 'Ninguno' and localidad = v.localidad) / count (v.localidad) "Ninguno"
from localidades l, votantes v
where v.localidad = l.idlocalidad
group by l.nombre, v.localidad;

--Cuenta el total de votantes de cada localidad
select count(v.localidad)
from votantes v
group by v.localidad;

--Cuenta el Nº de Doctorados en cada localidad
select count(v.localidad)
from votantes v
where v.estudiossuperiores = 'Doctorado'
group by v.localidad;
