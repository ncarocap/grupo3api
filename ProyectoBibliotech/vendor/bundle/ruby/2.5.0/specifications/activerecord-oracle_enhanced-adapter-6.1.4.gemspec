# -*- encoding: utf-8 -*-
# stub: activerecord-oracle_enhanced-adapter 6.1.4 ruby lib

Gem::Specification.new do |s|
  s.name = "activerecord-oracle_enhanced-adapter".freeze
  s.version = "6.1.4"

  s.required_rubygems_version = Gem::Requirement.new(">= 1.8.11".freeze) if s.respond_to? :required_rubygems_version=
  s.require_paths = ["lib".freeze]
  s.authors = ["Raimonds Simanovskis".freeze]
  s.date = "2021-04-01"
  s.description = "Oracle \"enhanced\" ActiveRecord adapter contains useful additional methods for working with new and legacy Oracle databases.\nThis adapter is superset of original ActiveRecord Oracle adapter.\n".freeze
  s.email = "raimonds.simanovskis@gmail.com".freeze
  s.extra_rdoc_files = ["README.md".freeze]
  s.files = ["README.md".freeze]
  s.homepage = "http://github.com/rsim/oracle-enhanced".freeze
  s.licenses = ["MIT".freeze]
  s.required_ruby_version = Gem::Requirement.new(">= 2.5.0".freeze)
  s.rubygems_version = "2.7.6.2".freeze
  s.summary = "Oracle enhanced adapter for ActiveRecord".freeze

  s.installed_by_version = "2.7.6.2" if s.respond_to? :installed_by_version

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_runtime_dependency(%q<activerecord>.freeze, ["~> 6.1.0"])
      s.add_runtime_dependency(%q<ruby-plsql>.freeze, [">= 0.6.0"])
    else
      s.add_dependency(%q<activerecord>.freeze, ["~> 6.1.0"])
      s.add_dependency(%q<ruby-plsql>.freeze, [">= 0.6.0"])
    end
  else
    s.add_dependency(%q<activerecord>.freeze, ["~> 6.1.0"])
    s.add_dependency(%q<ruby-plsql>.freeze, [">= 0.6.0"])
  end
end
