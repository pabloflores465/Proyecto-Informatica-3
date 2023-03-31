#include "documentacion.h"

documentacion::documentacion()
{
    this->cuentas[0]="Bancos";
    this->cuentas[1]="Iva por Cobrar";
    this->cuentas[2]="Inventario";
    this->cuentas[3]="Vehículos";
    this->cuentas[4]="Clientes";
    this->cuentas[5]="Gastos de Organización";
    this->cuentas[6]="Capital Social";
    this->cuentas[7]="Proveedores";
    this->cuentas[8]="Iva por Pagar";
    this->cuentas[9]="Prestaciones Laborales por Pagar";
    this->cuentas[10]="Depreciación Acumulada de Vehículos";
    this->cuentas[11]="Documentos por Pagar";
    this->cuentas[12]="Ventas";
    this->cuentas[13]="Alquileres";
    this->cuentas[14]="Sueldos de Administración";
    this->cuentas[15]="Sueldos de Ventas";
    this->cuentas[16]="Prestaciones Laborales";
    this->cuentas[17]="Depreciación Vehículos";
    this->cuentas[18]="Amortización de Gastos de Organización";
    this->cuentas[19]="Costo de Ventas";

    this->clasificacion[0]="Activo";
    this->clasificacion[1]="Activo";
    this->clasificacion[2]="Activo";
    this->clasificacion[3]="Activo";
    this->clasificacion[4]="Activo";
    this->clasificacion[5]="Activo";
    this->clasificacion[6]="Pasivo";
    this->clasificacion[7]="Pasivo";
    this->clasificacion[8]="Pasivo";
    this->clasificacion[9]="Pasivo";
    this->clasificacion[10]="Pasivo";
    this->clasificacion[11]="Pasivo";
    this->clasificacion[12]="Ingresos";
    this->clasificacion[13]="Gasto";
    this->clasificacion[14]="Gasto";
    this->clasificacion[15]="Gasto";
    this->clasificacion[16]="Gasto";
    this->clasificacion[17]="Gasto";
    this->clasificacion[18]="Gasto";
    this->clasificacion[19]="Gasto";

    this->descripcion[0]="Es la cuenta que se utiliza para registrar las operaciones de ingresos y egresos de dinero relacionadas con la actividad bancaria. En esta cuenta se registran los depósitos, cheques emitidos, transferencias bancarias, comisiones bancarias, entre otros.";
    this->descripcion[1]="Es el impuesto al valor agregado que un negocio ha cobrado a sus clientes y que aún no ha sido pagado. El IVA es un impuesto que se aplica en muchos países a la mayoría de las transacciones comerciales y es responsabilidad del negocio recolectar este impuesto y luego pagar al gobierno.";
    this->descripcion[2]="Es un activo corriente que representa los bienes y productos que un negocio tiene disponibles para su venta a los clientes. Es decir, es la mercancía o productos que el negocio tiene en su poder y que espera vender a un precio superior al costo de adquisición para obtener una ganancia.";
    this->descripcion[3]="son activos fijos que posee una empresa y se utilizan para llevar a cabo sus operaciones comerciales. Pueden ser vehículos de transporte de mercancías, vehículos de transporte de personal, maquinarias y equipos, entre otros.";
    this->descripcion[4]="Los clientes son personas, empresas u organizaciones que compran productos o servicios de una empresa a cambio de un pago. Los clientes son importantes para cualquier negocio, ya que generan ingresos y son una fuente de crecimiento y sostenibilidad.";
    this->descripcion[5]="Son los costos en los que incurre una empresa durante la etapa de creación y organización inicial, antes de comenzar a operar. Estos gastos incluyen los costos legales y de asesoría relacionados con la formación de la empresa, como el registro de la empresa, la obtención de permisos y licencias, y la elaboración de contratos y acuerdos.";
    this->descripcion[6]="Es el monto de dinero o valor que una empresa o corporación recibe de sus accionistas o socios, a cambio de la emisión y venta de acciones o participaciones en la empresa. El capital social representa la inversión inicial de los accionistas o socios y se utiliza para financiar las operaciones de la empresa.";
    this->descripcion[7]="Son aquellos que suministran los bienes o servicios necesarios para que una empresa pueda funcionar. Estos pueden ser empresas o personas que suministran una amplia variedad de bienes y servicios, incluyendo materias primas, maquinaria, servicios de transporte y logística, servicios de publicidad y marketing, servicios financieros, servicios legales, servicios de tecnología de la información y mucho más.";
    this->descripcion[8]="Es el impuesto sobre el valor agregado que una empresa o individuo debe pagar al Estado por la venta de bienes y servicios. El IVA es un impuesto indirecto que se cobra a las entidades finales y se basa en el valor agregado en cada etapa de la cadena de producción y distribución.";
    this->descripcion[9]="Son las obligaciones que una empresa tiene con sus empleados por concepto de beneficios y derechos adquiridos en el desempeño de su trabajo, pero que aún no se han liquidado o pagado completamente.";
    this->descripcion[10]="Es la disminución del valor de un vehículo que ha sido propiedad de una empresa durante un período de tiempo determinado y que ha sido utilizada en su operación. La depreciación es el costo anual que se le atribuye al vehículo por su uso, el desgaste y el paso del tiempo.";
    this->descripcion[11]="Son documentos financieros que representan una deuda pendiente de pago por parte de una empresa. Estos documentos son emitidos por el proveedor de bienes o servicios a la empresa y contienen información detallada sobre el monto de la deuda, las fechas de vencimiento y los términos de pago.";
    this->descripcion[12]="Pueden ser definidas como el proceso por el cual una empresa o individuo intercambia bienes o servicios por dinero u otro valor, con el objetivo de satisfacer las necesidades o deseos de los clientes. ";
    this->descripcion[13]="Es un gasto que una empresa incurre al utilizar un bien inmueble propiedad de un tercero. Los alquileres pueden ser de diferentes tipos, como alquiler de locales comerciales, alquiler de oficinas, alquiler de maquinaria, entre otros.";
    this->descripcion[14]="Son los salarios que se pagan a los empleados que trabajan en puestos administrativos dentro de una empresa. Estos puestos incluyen cargos como gerentes, supervisores, contadores, personal de recursos humanos y otros empleados que trabajan en áreas administrativas de la empresa.";
    this->descripcion[15]="Son los salarios que se pagan a los empleados que trabajan en el área de ventas de una empresa. Estos puestos incluyen cargos como vendedores, representantes de ventas, ejecutivos de cuentas, entre otros empleados que trabajan en el área comercial de la empresa.";
    this->descripcion[16]="Son los beneficios y derechos que tienen los empleados en virtud de su relación laboral con una empresa. Estas prestaciones pueden variar según la legislación laboral de cada país";
    this->descripcion[17]="Es el proceso contable mediante el cual se registra el desgaste y la pérdida de valor de un vehículo en el tiempo. Esta depreciación se produce debido al uso normal del vehículo, así como a su envejecimiento y obsolescencia.";
    this->descripcion[18]="Es el proceso contable mediante el cual se registra la disminución del valor de los gastos de organización en el tiempo. Estos gastos incluyen los costos incurridos por la empresa en la creación y organización inicial, antes de comenzar a operar, como el registro de la empresa, la obtención de permisos y licencias, y la elaboración de contratos y acuerdos.";
    this->descripcion[19]="Es el gasto directo en el que incurre una empresa para producir los bienes o servicios vendidos durante un período determinado. Este costo incluye el costo de los materiales, la mano de obra directa y los gastos generales directos asociados a la producción de bienes o servicios.";

};

QString documentacion::getCuentas(int indice){
    return cuentas[indice];
}

QString documentacion::getClasificacion(int indice){
    return clasificacion[indice];
}

QString documentacion::getDescripcion(int indice){
    return descripcion[indice];
}




