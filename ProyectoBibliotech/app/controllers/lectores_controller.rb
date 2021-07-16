class LectoresController < ApplicationController

  # GET /lectores
  def index
    @lectores = Lector.all

    # /lectores?rut_lector=
    @lectores = @lectores.where("rut_lector like :q", :q => "%#{params[:rut_lector]}%") if params[:rut_lector]

    render json: @lectores
  end

  # GET /lectores/1
  def show
    render json: Lector.find(params[:id])
  end

  # POST /lectores
  def create
    @lector = Lector.new(lector_params)

    if @lector.save
      render json: @lector, status: :created, location: @lector
    else
      render json: @lector.errors, status: :unprocessable_entity
    end
  end

  # PATCH/PUT /lectores/1
  def update
    if @lector.update(lector_params)
      render json: @lector
      #render json: @lector.where("rut_lector like :q", :q => "%#{params[:rut_lector]}%") if params[:rut_lector]
      #render json: @lector.where(rut_lector:params[:rut_lector])
    else
      render json: @lector.errors, status: :unprocessable_entity
    end
  end

private

  # Use callbacks to share common setup or constraints between actions.
  def set_lector
    @lector = Lector.find(params[:id])
  end

  # Only allow a list of trusted parameters through.
  def lector_params
    params.require(:lector).permit(:rut_lector, :nomb_lec, :ape_lec,
      :direccion, :correo_lec, :contrasena_lec, :tel_lec, :activo, :foto, :huella, :id_lector)
  end
  
end