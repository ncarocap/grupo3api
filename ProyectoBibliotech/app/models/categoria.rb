class Categoria < ApplicationRecord
    belongs_to :tipoproducto
    # belongs_to :productos
    has_many :productos
end