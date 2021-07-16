class ReservasController < ApplicationController

    # GET /reservas
    def index
      render json: Reserva.all
    end
  
    # GET /reservas/1
    def show
      render json: Reserva.find(params[:id])
    end

    # POST /reservas
    def create
      @reserva = Reserva.new(reserva_params)

      if @reserva.save
        render json: @reserva, status: :created, location: @reserva
      else
        render json: @reserva.errors, status: :unprocessable_entity
      end
    end

private

    # Use callbacks to share common setup or constraints between actions.
    def set_reserva
      @reserva = Reserva.find(params[:id])
    end

    # Only allow a list of trusted parameters through.
    def reserva_params

      params.require(:reserva).permit(:rut_lector, :fecha_reserva, :id_producto, :id_reserva)
    end
  
end