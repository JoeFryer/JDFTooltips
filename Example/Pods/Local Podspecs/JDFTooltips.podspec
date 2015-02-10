#
# Be sure to run `pod lib lint JDFTooltips.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# Any lines starting with a # are optional, but encouraged
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "JDFTooltips"
  s.version          = "1.0"
  s.summary          = "A simple library for showing tooltip-like popups on iOS"
  s.description      = <<-DESC
                       JDFTooltips is simple library for showing tooltip-like popups on iOS
                       DESC
  s.homepage         = "https://github.com/JoeFryer/JDFTooltips"
  s.license          = 'MIT'
  s.author           = { "Joe Fryer" => "joe.d.fryer@gmail.com" }
  s.source           = { :git => "https://github.com/JoeFryer/JDFTooltips.git", :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/joefryer88'

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Pod/Classes'

  s.frameworks = 'UIKit'
end
