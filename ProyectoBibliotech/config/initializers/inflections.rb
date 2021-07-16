# Be sure to restart your server when you modify this file.

# Add new inflection rules using the following format. Inflections
# are locale specific, and you may define rules for as many different
# locales as you wish. All of these examples are active by default:
# ActiveSupport::Inflector.inflections(:en) do |inflect|
#   inflect.plural /^(ox)$/i, '\1en'
#   inflect.singular /^(ox)en/i, '\1'
#   inflect.irregular 'person', 'people'
#   inflect.uncountable %w( fish sheep )
# end

# These inflection rules are supported but not enabled by default:
# ActiveSupport::Inflector.inflections(:en) do |inflect|
#   inflect.acronym 'RESTful'
# end

ActiveSupport::Inflector.inflections(:en) do |inflect|
    inflect.plural /^(\w+(a|o))$/i, '\1s'             # persona -> personas
    inflect.singular /^(\w+)(a|o)s$/i, '\1\2'         # personas -> persona
  
    inflect.plural /^(\w+(d|l|n|r|s))$/i, '\1es'      # pais -> paises
    inflect.singular /^(\w+)(d|l|n|r|s)es$/i, '\1\2'  # paises -> pais
  
    inflect.plural /^(\w+)z$/i, '\1ces'               # actriz -> actrices
    inflect.singular /^(\w+)ces$/i, '\1z'             # actrices -> actriz
  
    inflect.irregular 'lector', 'lectores'    
    inflect.uncountable %w( sintesis )                # dosis <-> dosis
  end
  