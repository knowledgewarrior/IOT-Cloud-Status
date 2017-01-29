#!/usr/bin/env ruby

require 'rubygems'
require 'dogapi'

# Use your DataDog api and app key:
api_key = 'xxxxxxxxxxxxxxxx'
app_key = 'xxxxxxxxxxxxxxxxxxxxxxx'

from = Time.now.to_i - 300
to = Time.now.to_i

dog = Dogapi::Client.new(api_key, app_key)

query = 'avg:query.timeout.count{*}'
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

