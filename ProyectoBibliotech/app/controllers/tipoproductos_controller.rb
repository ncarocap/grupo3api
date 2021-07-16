class TipoproductosController < ApplicationController

    # GET /tipoproductos
    def index
      render json: Tipoproducto.all
    end
  
    # GET /tipoproductos/1
    def show
      render json: Tipoproducto.find(params[:id])
    end
  
end