Rails.application.routes.draw do
  # For details on the DSL available within this file, see https://guides.rubyonrails.org/routing.html
  resources :productos, defaults: { format: 'json' }
  resources :lectores, defaults: { format: 'json' }
  resources :categorias, defaults: { format: 'json' }
  resources :tipoproductos, defaults: { format: 'json' }
  resources :reservas, defaults: { format: 'json' }
  resources :prestamos, defaults: { format: 'json' }
  resources :detalleprestamos, defaults: { format: 'json' }
end
