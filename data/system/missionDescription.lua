missionDescription = {
	callbacks = {
	}
}

function missionDescription:onMissionDescription(player, descriptionId)

	if self.callbacks[descriptionId] then
	
		local result = self.callbacks[descriptionId](player, descriptionId)
		
		if not (type(result) == 'string') then
			print("missionDescription:onMissionDescription(player, descriptionId) - ERROR! callback for : " .. descriptionId .. " is not returning a string.")
			return descriptionId
		end
		
		return result
	end
	
	print("missionDescription:onMissionDescription(player, descriptionId) - ERROR! No callback for description: " .. descriptionId)
	
	return descriptionId
end

function missionDescription:addCallback(descriptionId, callback)
	self.callbacks[descriptionId] = callback
end

local function beingCoolCallback( player, descriptionId )
	local t = {'Not cool :(', 'Cool :)', 'Ask me again.', 'Maybe tomorrow.'}
	
	return t[math.random(1, #t)]
end

missionDescription:addCallback('BeingCoolDescriptionId', beingCoolCallback)
