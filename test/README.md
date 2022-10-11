## Testing
### Pre-requisites

- C++ compiler and runtime environment are available
- `lcov` is installed (for coverage report generation)

### Running Unit Tests

In `test` directory, run the `make test` command:  
```  
$ cd src
$ make test
:
........................
OK (32 tests, 32 ran, 73 checks, 0 ignored, 0 filtered out, 3 ms)
```  

To analyze code coverage data, run `make coverage` command in the same directory:  
```
$ make coverage
```  
To export a text summary to a file, run:
```
$ make coverage_report_text_summary
```  
To export to an html with source code view, run:
```
make coverage_report_html_view
```

The report will be placed in the project's root directory under `reports/coverage`

NOTE:  
Only the text output is auto generated and pushed during the `ci` execution.  
Run the `make coverage_report_html_view` command to manually to check the source code view.
