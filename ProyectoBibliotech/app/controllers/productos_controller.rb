class ProductosController < ApplicationController

    # GET /productos
    def index
      # render json: Producto.all

      @productos = Producto.all

      # /productos?lugar_prest=
      @productos = @productos.where(lugar_prest: 'Sala') if params[:lugar_prest] == 'Sala'
      @productos = @productos.where(lugar_prest: 'Sala y Domicilio') if params[:lugar_prest] == 'Sala y Domicilio'
      # @productos = Producto.all if params[:lugar_prest] == ''

      # /productos?titulo=
      #@productos = @productos.where(titulo:params[:titulo]) if params[:titulo]
      @productos = @productos.where("titulo like :q", :q => "%#{params[:titulo]}%") if params[:titulo]
      @productos = @productos.where("autor like :q", :q => "%#{params[:autor]}%") if params[:autor]

      # /productos?id_categoria=
      @productos = @productos.where(id_categoria:10) if params[:id_categoria] == '10'
      @productos = @productos.where(id_categoria:11) if params[:id_categoria] == '11'
      @productos = @productos.where(id_categoria:12) if params[:id_categoria] == '12'
      @productos = @productos.where(id_categoria:13) if params[:id_categoria] == '13'
      @productos = @productos.where(id_categoria:20) if params[:id_categoria] == '20'
      @productos = @productos.where(id_categoria:21) if params[:id_categoria] == '21'
      @productos = @productos.where(id_categoria:30) if params[:id_categoria] == '30'
      @productos = @productos.where(id_categoria:31) if params[:id_categoria] == '31'

      render json: @productos
    end
  
    # GET /productos/1
    def show
      render json: Producto.find(params[:id])
    end
  
end