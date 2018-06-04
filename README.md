- 02/06 Sat (9am - 6pm)
  1. Studied the requirements.
  2. Spent some time to consolidate the knowledge of RESTFul API.
  3. Initially implemented a test app who acts as a terminal based on Python/Requests/Json.
  4. Spent some time to setup cMock and wrote a simple test case.
  5. Spent some time to setup libmicrohttpd.
  6. Make "create a terminal" work between test terminal and app with some dummy code. 
    
- 03/06 Sun (10am - 12:30pm) (will be in the church in the afternoon :-))
  1. Restructured the code
  2. Initial implementation of terminal_management.
  3. Implemented ParseEndPointFromUrl and unit tested it.

- 04/06 Mon (8:30 - 7:30pm) 
  Coninued the work...
  So far I've achieved 
  - Application
    - I used Dev-c++ as an IDE to create a prject for this test. 
    - create terminals 
      implemented, but it has a problem to get post data correcly. From libmicrohttpd's doc upload_data in the request handling call back function is empty for the first time and afterwards it will has value. It failed acceptance test anyway. 
    - get terminal details
      implemented, tested.
    - get termainl list
      implementation not complete.
  - Unit test
    - I used cmock to unit test functions in data_handler.c and terminal_manager.c.
    - Since I had not much time to learn how to get cmock integrted into my project I copied rake files from an example in cmock, and I hard coded the path in a couple of places. Need to use env variable to them.
    - To run it
      - install cmock.
      - modify UTest/gcc.yml : line 12 according to your cmock path.
      - modify UTest/rakefile_helper.rb : lines 3,4,5 according to your cmock path. 
      - under UTest, run cmd 'rake'.
  - Acceptance test
    - I used python to write a test app, under folder ATest.
    - It is used to test web APIs create_terminal and get_terminal_details.
    - Verification needs to be improved.
    - Need to adopt an automation framework to test automatically.
  - Other issues needed to address
    - Better understand libmicrohttpd's threading mode and choose the right one.
    - Buffer/memory management. Check mem leak with valgrind.
    - Address inconsistent code style.
    - Unit test end_points.c
