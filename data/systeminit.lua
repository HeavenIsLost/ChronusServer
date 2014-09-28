dofile("data/reloadsystem.lua")

--just add this and the system will load this file( lib.lua ) when tfs starts the script system
-- and you it can reloaded with /reload lib
reloadSystem:addEntry("Lib", {"lib"}, "data/lib/lib.lua")

--the last thing, will load all files for the first time
reloadSystem:executeAllEntrys()