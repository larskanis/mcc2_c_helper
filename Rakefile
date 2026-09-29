# frozen_string_literal: true

require "bundler/gem_tasks"
require "minitest/test_task"

Minitest::TestTask.create

require "rubocop/rake_task"

RuboCop::RakeTask.new

require "rake/extensiontask"

task build: :compile

GEMSPEC = Gem::Specification.load("mcc2_c_helper.gemspec")

Rake::ExtensionTask.new("mcc2_c_helper", GEMSPEC) do |ext|
  ext.lib_dir = "lib/mcc2_c_helper"
end

task default: %i[clobber compile test rubocop]
