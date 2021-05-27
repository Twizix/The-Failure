@echo off
rem fast copy dependencies by D. Buckstein
md "%~dp0%3"
copy "%~dp0%1" "%~dp0%3" /y
copy "%~dp0%2" "%~dp0%3" /y
