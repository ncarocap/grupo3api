class PrestamosController < ApplicationController

  # GET /prestamos
  def index

    @prestamos = Prestamo.all
    @detalleprestamos = Detalleprestamo.all

    @detalleprestamos = @detalleprestamos.where(id_prestamo: params[:id_prestamo]) if params[:id_prestamo]

    # /detalleprestamos?lugar=
    @detalleprestamos = @detalleprestamos.where(lugar: 'Sala') if params[:lugar] == 'Sala'
    @detalleprestamos = @detalleprestamos.where(lugar: 'Domicilio') if params[:lugar] == 'Domicilio'
    @detalleprestamos = @detalleprestamos.where(lugar: 'Sala y Domicilio') if params[:lugar] == 'Sala y Domicilio'

    render json: @detalleprestamos


    #render json: @prestamos
  end    

  # GET /prestamos/1
  def show
    render json: Prestamo.find(params[:id])
  end

end