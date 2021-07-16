class CategoriasController < ApplicationController

    # GET /categorias
    def index

      @categorias = Categoria.all

      # /categorias?id_tipo_prod=
      @categorias = @categorias.where(id_tipo_prod:1) if params[:id_tipo_prod] == '1'
      @categorias = @categorias.where(id_tipo_prod:2) if params[:id_tipo_prod] == '2'
      @categorias = @categorias.where(id_tipo_prod:3) if params[:id_tipo_prod] == '3'

      render json: @categorias
    end    
  
    # GET /categorias/1
    def show
      render json: Categoria.find(params[:id])
    end
  
end