#!/usr/bin/env ruby

require 'rubygems'
require 'dogapi'

api_key = 'c48ff314a34d362b588cf25912c4992a'
app_key = 'c52f20285c528dd33fd4d41880b449b5eaff7c78'

from = Time.now.to_i - 300
to = Time.now.to_i

dog = Dogapi::Client.new(api_key, app_key)

query = 'avg:avid.acs.gw.query.timeout.count{*}'
qdata = dog.get_points(query, from, to)
timeouts = qdata[1]["series"][0]["pointlist"].last[1].round(2)
#p timeouts

if timeouts <= 39.99 
  cloudstatus = {"status" => "green"}
else 
  cloudstatus = {"status" => "red"}
end

File.open("status.json","w") do |f|
  f.write(cloudstatus.to_json)
end

