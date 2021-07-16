class DetalleprestamosController < ApplicationController

  # GET /detalleprestamos
  def index

    @detalleprestamos = Detalleprestamo.all


    # /detalleprestamos?lugar=        id_prestamo
    @detalleprestamos = @detalleprestamos.where(lugar: 'Sala') if params[:lugar] == 'Sala'
    @detalleprestamos = @detalleprestamos.where(lugar: 'Domicilio') if params[:lugar] == 'Domicilio'
    @detalleprestamos = @detalleprestamos.where(lugar: 'Sala y Domicilio') if params[:lugar] == 'Sala y Domicilio'
    @detalleprestamos = @detalleprestamos.where(id_producto: params[:id_producto]) if params[:id_producto]

    render json: @detalleprestamos
  end    

  # GET /detalleprestamos/1
  def show
    render json: Detalleprestamo.find(params[:id])
  end

end