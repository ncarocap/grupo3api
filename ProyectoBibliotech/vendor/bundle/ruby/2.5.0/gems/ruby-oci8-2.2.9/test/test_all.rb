srcdir = File.dirname(__FILE__)

require 'oci8'
require "#{srcdir}/config"

require "#{srcdir}/test_oradate"
require "#{srcdir}/test_oranumber"
require "#{srcdir}/test_bind_array.rb"
require "#{srcdir}/test_bind_string"
require "#{srcdir}/test_bind_time"
require "#{srcdir}/test_bind_raw"
require "#{srcdir}/test_bind_integer"
if $test_clob
  require "#{srcdir}/test_clob"
end

require "#{srcdir}/test_break"
require "#{srcdir}/test_oci8"
require "#{srcdir}/test_datetime"
require "#{srcdir}/test_connstr"
require "#{srcdir}/test_metadata"
require "#{srcdir}/test_array_dml"
require "#{srcdir}/test_rowid"
require "#{srcdir}/test_appinfo"
require "#{srcdir}/test_oracle_version"
require "#{srcdir}/test_error"
require "#{srcdir}/test_connection_pool"
require "#{srcdir}/test_object"
require "#{srcdir}/test_properties.rb"

if OCI8.respond_to? :encoding
  require "#{srcdir}/test_encoding"
end

if $oracle_version >= OCI8::ORAVER_12_1
  require "#{srcdir}/test_package_type"
  require "#{srcdir}/test_bind_boolean.rb"
end

# Ruby/DBI
begin
  require 'dbi'
rescue LoadError
  begin
    require 'rubygems'
    require 'dbi'
  rescue LoadError
    dbi_not_found = true
  end
end
unless dbi_not_found
  require "#{srcdir}/test_dbi"
  if $test_clob
    require "#{srcdir}/test_dbi_clob"
  end
end
