# frozen_string_literal: true

require "test_helper"

class TestMcc2CHelper < Minitest::Test
  def test_that_it_has_a_version_number
    refute_nil ::Mcc2CHelper::VERSION
  end

  def test_bgra_to_bgr
    assert_equal "\n\0\tbgrBGR".b, Mcc2CHelper.bgra_to_bgr("\n\0\t\rbgraBGRA".b)
    assert_equal "\n\0\tbgr".b, Mcc2CHelper.bgra_to_bgr("\n\0\t\rbgraBGR".b)
  end
end
