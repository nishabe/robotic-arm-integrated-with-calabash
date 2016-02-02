Given(/^the app has launched$/) do
  wait_for do
    !query("*").empty?
  end
end

And(/^I have done a specific thing$/) do
  # Example: Given I am logged in
  #  wait_for do
  #    !query("* marked:'username'").empty?
  #  end
  #
  #  touch("* marked:'username'")
  #  wait_for_keyboard
  #  keyboard_enter_text("cleveruser27")
  #
  #  touch("* marked:'password'")
  #  wait_for_keyboard
  #  keyboard_enter_text("pa$$w0rd")
  #
  #  wait_for_element_exists("* marked:'Login'")
  #  touch("* marked:'Login'")

  # Remember: any Ruby is allowed in your step definitions
  did_something = true

  unless did_something
    fail 'Expected to have done something'
  end
end

When(/^I tap on Swipe Now$/) do
  # Example: When I create a new entry
  #  tap("* marked:'new_entry'")
  #  wait_for_keyboard
  #  keyboard_enter_text("* marked:'entry_title'", 'My Entry')
  #
  touch ("view marked:'Swipe Now'")
end

Then(/^magic happens$/) do
  # Example: Then I should see the entry on my home page
  #  wait_for_element_exists("* text:'My Entry'")
  system("cd ../../")
  system("python SerialTest.py")
  sleep 8
end

And(/^I am happy$/) do
  touch ("view marked: 'OK'")
end
