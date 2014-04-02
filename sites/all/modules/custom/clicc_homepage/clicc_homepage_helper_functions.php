<?php

// Get laptops
function get_laptops_array() {
	// Access webservice for the laptops array
	$jsonurl = "http://webservices.library.ucla.edu/laptops/available";
	$json_output = json_decode(file_get_contents($jsonurl));
	foreach ($json_output->laptops as $laptop)
	{
		$avail_dict[] = array("location" => $laptop->publicName, "count" => $laptop->availableCount);
	}
	
	return $avail_dict;
 }  

// These functions are used for getting the availability schedules for 

date_default_timezone_set('America/Los_Angeles');
function checkOpenCloseTime($library) {
	$libID = 0;
	if ($library == "YRL")
		$libID = 48;
	if ($library == "Powell")
		$libID = 54;
	if ($library == "Classrooms") // Monday-Thursday 8am-11pm. Friday 8am-6pm. Sat/Sun closed.
		$libID = 55;
	$openCloseArr = array(
		'open' => 0,
		'close' => 0,);
	// Special case for classroom only: webservice data is incorrect
	if ($library == "Classrooms") {
		$now = date('l');
		if ($now == 'Saturday' || $now == 'Sunday') {
			$openCloseArr['open'] = 0;
			$openCloseArr['close'] = 0;
		}
		else if ($now == 'Friday') {
			$openCloseArr['open'] = 8;
			$openCloseArr['close'] = 18;
		}
		else { // Monday-Thursday
			$openCloseArr['open'] = 8;
			$openCloseArr['close'] = 23;
		}
		return $openCloseArr;
	}
	else {
		$hoursArr = json_decode(file_get_contents('http://webservices.library.ucla.edu/libservices/hours/unit/' . $libID), true);
		switch (date('N')){
			case 7:
				if($hoursArr['unitSchedule']['sunClosed'] == "true"){
					$openCloseArr['open'] =  0;
					$openCloseArr['close'] =  0;
				}
				elseif(!empty($hoursArr['unitSchedule']['sunCloses']) && !empty($hoursArr['unitSchedule']['sunOpens'])){
					$opens = strtotime($hoursArr['unitSchedule']['sunOpens']);
					$closes= strtotime($hoursArr['unitSchedule']['sunCloses']);
					$opensString = strftime('%I %p', strtotime(substr($opens, strpos($opens, 'T')+1, 5)));
					$closesString = strftime('%I %p', strtotime(substr($closes, strpos($closes, 'T')+1, 5)));
					$opensInt = (int)substr($opensString,0,2);
					if(substr($opensString, 3,5) == "PM")
						$opensInt = $opensInt + 12;
					$closesInt = (int)substr($closesString,0,2);
					if(substr($closesString, 3,5) == "PM")
						$closesInt = $closesInt + 12;
					$openCloseArr['open'] = $opensInt;
					$openCloseArr['close'] = $closesInt;
				}
				break;
			case 6:
				if($hoursArr['unitSchedule']['satClosed'] == "true"){
					$openCloseArr['open'] =  0;
					$openCloseArr['close'] =  0;
				}
				else if (!empty($hoursArr['unitSchedule']['satOpens']) && !empty($hoursArr['unitSchedule']['satCloses'])){
					$opens = strtotime($hoursArr['unitSchedule']['satOpens']);
					$closes= strtotime($hoursArr['unitSchedule']['satCloses']);
					$opensString = strftime('%I %p', strtotime(substr($opens, strpos($opens, 'T')+1, 5)));
					$closesString = strftime('%I %p', strtotime(substr($closes, strpos($closes, 'T')+1, 5)));
					$opensInt = (int)substr($opensString,0,2);
					if(substr($opensString, 3,5) == "PM")
						$opensInt = $opensInt + 12;
					$closesInt = (int)substr($closesString,0,2);
					if(substr($closesString, 3,5) == "PM")
						$closesInt = $closesInt + 12;
					$openCloseArr['open'] = $opensInt;
					$openCloseArr['close'] = $closesInt;
				}
				break;
			case 5:
				if($hoursArr['unitSchedule']['friClosed'] == "true"){
					$openCloseArr['open'] =  0;
					$openCloseArr['close'] =  0;
				}
				else if (!empty($hoursArr['unitSchedule']['friOpens']) && !empty($hoursArr['unitSchedule']['friCloses'])) {
					$opens = date($hoursArr['unitSchedule']['friOpens']);
					$closes = date($hoursArr['unitSchedule']['friCloses']);
					$opensString = strftime('%I %p', strtotime(substr($opens, strpos($opens, 'T')+1, 5)));
					$closesString = strftime('%I %p', strtotime(substr($closes, strpos($closes, 'T')+1, 5)));
					$opensInt = (int)substr($opensString,0,2);
					if(substr($opensString, 3,5) == "PM")
						$opensInt = $opensInt + 12;
					$closesInt = (int)substr($closesString,0,2);
					if(substr($closesString, 3,5) == "PM")
						$closesInt = $closesInt + 12;
					$openCloseArr['open'] = $opensInt;
					$openCloseArr['close'] = $closesInt;
				}
				break;
			case 4:
			case 3:
			case 2:
			case 1:
				if($hoursArr['unitSchedule']['monThursClosed'] == "true"){
					$openCloseArr['open'] =  0;
					$openCloseArr['close'] =  0;
				}
				else if (!empty($hoursArr['unitSchedule']['monThursOpens']) && !empty($hoursArr['unitSchedule']['monThursCloses'])) {
					$opens = strtotime($hoursArr['unitSchedule']['monThursOpens']);
					$closes = strtotime($hoursArr['unitSchedule']['monThursCloses']);
					$opensString = strftime('%I %p', strtotime(substr($opens, strpos($opens, 'T')+1, 5)));
					$closesString = strftime('%I %p', strtotime(substr($closes, strpos($closes, 'T')+1, 5)));
					$opensInt = (int)substr($opensString,0,2);
					if(substr($opensString, 3,5) == "PM")
						$opensInt = $opensInt + 12;
					$closesInt = (int)substr($closesString,0,2);
					if(substr($closesString, 3,5) == "PM")
						$closesInt = $closesInt + 12;
					$openCloseArr['open'] = $opensInt;
					$openCloseArr['close'] = $closesInt;
				}
				break;
				
		}
			
		return $openCloseArr;
	}
}

class Space {
	public $startDate;
	public $endDate;
	public $libraryName;
	public $hasReservation;
	public $roomNum;
	public $integerStartTime; // In half hours
	public $integerDuration; // In half hours
	
	public function __construct($res) {
		if (empty($res)){
			$this->hasReservation = false;
		}
		else {
			$this->startDate = strtotime($res["startDate"]);
			$this->endDate = strtotime($res["endDate"]);
			$this->libraryName = $res["library"];
			$this->hasReservation = true;
			$this->setRoomNum($res["resID"]);
			$this->setTime($res);
		}
		if ($this->startDate == "" && $this->endDate == "") {
			$this->hasReservation = false;
		}
	}
	
	// Converts to the half hour of the day
	public function convertDateToInt($date){
		$beginDay = date('Y-m-d');
		$numOfSecondsInHalfHour = 1800;
		return ($date - strtotime($beginDay))/$numOfSecondsInHalfHour;
		
	}
	
	public function setTime($res){
		$this->integerStartTime = $this->convertDateToInt($this->startDate);
		$this->integerDuration = ($this->convertDateToInt($this->endDate) - $this->integerStartTime);
	}
	
	public function setLibrary($lib){
		$this->library = $lib;
	}
	
	public function setRoomNum($resID){
		
		if($this->libraryName == "Powell"){
			switch($resID){
				case 128: // "College Group Study Room A"
					$this->roomNum = 0;
					break;
				case 129: // "College Group Study Room B"
					$this->roomNum = 1;
					break;
				case 130: // "College Group Study Room C"
					$this->roomNum = 2;
					break;
				case 131: // "College Group Study Room D"
					$this->roomNum = 3;
					break;
				case 132: // "College Group Study Room E"
					$this->roomNum = 4;
					break;
				case 169: // "College Group Study Room F"
					$this->roomNum = 5;
					break;
			}
		}
		elseif($this->libraryName == "YRL"){
			switch($resID){
				case 117: // "Room 1 (11921) w/screen"
					$this->roomNum = 0;
					break;
				case 118: // "Room 2 (11923)"
					$this->roomNum = 1;
					break;
				case 195:// "Room 3 (11925) w/screen"
					$this->roomNum = 2;
					break;
				case 196: // "Room 4 (11927)"
					$this->roomNum = 3;
					break;
				case 197: // "Room 5 (11929) w/screen"
					$this->roomNum = 4;
					break;
				case 198: // "Room 6 (11931)",
					$this->roomNum = 5;
					break;
				case 199: // "Room 7 (11941) w/screen"
					$this->roomNum = 6;
					break;
				case 200: // "Room 8 (11943)"
					$this->roomNum = 7;
					break;
				case 201: // "Room 9 (11945) w/screen"
					$this->roomNum = 8;
					break;
				case 202: // "Room 10 (11947)"
					$this->roomNum = 9;
					break;
				case 203: // "Room 11 (11942) w/screen"
					$this->roomNum = 10;
					break;
				case 204: // "Room 12 (11741) w/screen"
					$this->roomNum = 11;
					break;
				case 205: // "Room 13 (11630G) w/screen"
					$this->roomNum = 12;
					break;
				case 206: // "Room 14 (11630H) w/screen"
					$this->roomNum = 13;
					break;
				case 207: // "Room 15 (11630J) w/screen"
					$this->roomNum = 14;
					break;
				case 217: // Pod R1
					$this->roomNum = 15;
					break;
				case 218:// Pod R2
					$this->roomNum = 16;
					break;
				case 222:// Pod R3
					$this->roomNum = 17;
					break;
				case 223:// Pod R4
					$this->roomNum = 18;
					break;
				case 225:// Pod R5
					$this->roomNum = 19;
					break;
				case 226:// Pod R6
					$this->roomNum = 20;
					break;
				case 227:// Pod R7
					$this->roomNum = 21;
					break;
				case 228:// Pod R8
					$this->roomNum = 22;
					break;
				case 229:// Pod R9
					$this->roomNum = 23;
					break;
				case 230:// Pod R10
					$this->roomNum = 24;
					break;
				case 231:// Pod R11
					$this->roomNum = 25;
					break;
				case 232:// Pod R12
					$this->roomNum = 26;
					break;
				case 233:// Pod R13
					$this->roomNum = 27;
					break;
				case 234:// Pod R14
					$this->roomNum = 28;
					break;
				case 235:// Pod R15
					$this->roomNum = 29;
					break;
				case 236:// Pod R16
					$this->roomNum = 30;
					break;
				case 237:// Pod R17
					$this->roomNum = 31;
					break;
				case 238:// Pod R18
					$this->roomNum = 32;
					break;
				case 239:// Pod R19
					$this->roomNum = 33;
					break;
				case 240:// Pod R20
					$this->roomNum = 34;
					break;					
				
			}
		}
		else{
			$this->roomNum = -1;
		}
	}
}

class Schedule {
	public $spaceArr;
	public $libraryName = "";
	public $numSpacesInLibrary;
	
	public function __construct($library)
	{
		$this->libraryName = $library;
		$this->createSchedule();
	}
	
	public function getLibraryName(){
		return $this->libraryName;
	}
	
	public function createSchedule() {
		$numSpacesInLibrary;
		if ($this->libraryName == "Powell") {
			$jsonObject = json_decode(file_get_contents("http://webservices-dev.library.ucla.edu/irma/schedules/studyrooms/now/Powell"), true);
			$this->numSpacesInLibrary = 6;
		}
		else if ($this->libraryName == "YRL") {
			$jsonObject = json_decode(file_get_contents("http://webservices-dev.library.ucla.edu/irma/schedules/studyrooms/now/YRL"), true);
			$this->numSpacesInLibrary = 35;
		}
		else if ($this->libraryName == "YRL GSS") {
			$jsonObject = json_decode(file_get_contents("http://webservices-dev.library.ucla.edu/irma/schedules/studyrooms/now/YRL"), true);
			$this->numSpacesInLibrary = 15;
		}
		else if ($this->libraryName == "YRL Pods") {
			$jsonObject = json_decode(file_get_contents("http://webservices-dev.library.ucla.edu/irma/schedules/studyrooms/now/YRL"), true);
			$this->numSpacesInLibrary = 20;
		}
		else{
			echo("Incorrect Library Name Input. Please use 'Powell' or 'YRL' or 'YRL GSS' or 'YRL Pods' only");
			break;
		}
		//iterate number of half hours from now
		$blankArray = array(
			"schedID" => "",
			"resID" => "",
			"grpID" => "",
			"resTypeID" => "",
			"title" => "",
			"library" => "",
			"capacity" => "",
			"startDate" => "",
			"endDate" => "",
			"numAttendees" => "",
			"displayOrder" => "",
			"roomName" => "",
			);
		
		// Create empty spaceArr first
		$numOfHalfHoursInDay = 48;
		for($j=0; $j < $numOfHalfHoursInDay; $j++){
			// Iterate number of spaces in the library (35 for YRL, 15 for YRL GSS, 20 for YRL Pods, 6 for Powell)
			for ($k=0; $k < $this->numSpacesInLibrary; $k++){
				$this->spaceArr[$k][$j] = new Space($blankArray);
				$this->spaceArr[$k][$j]->setLibrary = $this->libraryName;
			}
		}
		
		$spacesReserved = $jsonObject["groups"];
		
		// Don't know what this case is for? Legacy?
		if (sizeof($spacesReserved) == 12 && empty($spacesReserved[11])){
			$space = new Space($spacesReserved);
			for($j=0; $j < $space->integerDuration; $j++){
				$this->spaceArr[$space->roomNum][$space->integerStartTime + $j] = $space; //Still number of half hours from now
			}
		}
		else if (sizeof($spacesReserved) != 0 ){
			$numSpacesReserved = sizeof($spacesReserved);
			$foundSpace = false;
			for ($i = 0; $i < $numSpacesReserved; $i++) {
				if ($this->libraryName == "Powell" || $this->libraryName == "YRL") {
					$res = $spacesReserved[$i];
					$space = new Space($res);
					$foundSpace = true;
				}
				else if ($this->libraryName == "YRL GSS") { // roomName starts with "G"
					if (substr($spacesReserved[$i]["roomName"], 0, 1) == "G") {
						$res = $spacesReserved[$i];
						$space = new Space($res);
						$foundSpace = true;
					}
				}
				else if ($this->libraryName == "YRL Pods") { // roomName starts with "media:scape"
					if (substr($spacesReserved[$i]["roomName"], 0, 11) == "media:scape") {
						$res = $spacesReserved[$i];
						$space = new Space($res);
						$foundSpace = true;
					}
				}
				if ($foundSpace) {
					for($j=0; $j < $space->integerDuration; $j++){
						// Stores reservation for every half hour slot that it's using up
						$this->spaceArr[$space->roomNum][$space->integerStartTime + $j] = $space; //Still number of half hours from now
					}
				}
				$foundSpace = false;
			}
		}
		$this->freeReservations();
	}
	
	// This function is used to clear up any reservations whose dates/times have already passed
	public function freeReservations() {
		$numOfHalfHoursInDay = 48;
		$currentTime = date('Y-m-d H:i');
		for ($i = 0; $i < $this->numSpacesInLibrary; $i++) {
			for ($j = 0; $j < $numOfHalfHoursInDay; $j++) {
				if ($currentTime > date('Y-m-d H:i', $this->spaceArr[$i][$j]->endDate)) {
					$this->spaceArr[$i][$j]->hasReservation = false;
				}
			}
		}
	}
	
	public function nextOpenReservation(){
		date_default_timezone_set('America/Los_Angeles');
		$numHalfHoursFromNow = 0;
		$date = new DateTime();
		$numOfHalfHoursInDay = 48;
		for ($i = 0; $i < $numOfHalfHoursInDay; $i++) {
			for($j = 0; $j < $this->numSpacesInLibrary; $j++) {
				if (!$this->spaceArr[$j][$i]->hasReservation) {
					$numHalfHoursFromNow = $i;
					break;
				}
			}
			if($date != "Thursday"){
				break;
			}
		}
		
		$result = $date->format('Y-m-d H:i');
		return $numHalfHoursFromNow;
	}
	
	// Function to get the next reservation in the $numOfHalfHours exactly
	public function nextOpenReservationTarget($targetNumOfHalfHours) {
		date_default_timezone_set('America/Los_Angeles');	
		$currentTimeInHalfHours = 2 * date('H');
		if (date('i') >= 30) {
			$currentTimeInHalfHours += 1;
		}
		$numOfHalfHoursInDay = 48;
		$earliestRoom = -1; // Not actually used but good information to keep on hand in case we need which room is available
		$earliestHalfHour = 1000;
		$earliestWeight = 1000; // Used to find which half hour is "earlier" - the closer it is to the beginning of current time in half hours, the earlier
		for ($i = 0; $i < $this->numSpacesInLibrary; $i++) { // For this space, we want to find an available slot
			$halfHourCount = 0; // Counts how many consecutive free slots we've found so far
			$foundAvailableSlot = false; // This is used to tell where we started counting
			$availableSlotStart = 1000; // Keeps track of when the first free slot is
			$halfHour = $currentTimeInHalfHours + 1; // Look one ahead, can't reserve for a time that has already passed
			if ($halfHour > 47) {
				$halfHour = 0;
			}
			for ($count = 0; $count < $numOfHalfHoursInDay; $count++) {
				if (!$this->spaceArr[$i][$halfHour]->hasReservation) { // If this slot has no reservation
					if (!$foundAvailableSlot) { // First time we encounter an available slot
						$currentWeight = $count;
						$foundAvailableSlot = true;
						$availableSlotStart = $halfHour;
						$halfHourCount++;
						$halfHour++;
						if ($halfHour > 47) {
							$halfHour = 0;
						}
					}
					else { // We are finding consecutive free slots
						$halfHourCount++;
						$halfHour++;
						if ($halfHour > 47) {
							$halfHour = 0;
						}
					}
					if ($halfHourCount == $targetNumOfHalfHours) { // If we found the target number of consecutive free slots
						if ($currentWeight < $earliestWeight) {
							$earliestWeight = $currentWeight;
							$earliestRoom = $i;
							$earliestHalfHour = $availableSlotStart;
						}
						break;
					}
				}
				else { // There is a reservation in the way before we reach the target number of consecutive free slots
					$halfHour++;
					if ($halfHour > 47) {
						$halfHour = 0;
					}
					$halfHourCount = 0;
					$foundAvailableSlot = false;
				}
			}
		}
		return $earliestHalfHour;
	}

}

function convertHalfHourToTime($halfHour) {
	// $halfHour is an integer 0 to 47
	if ($halfHour == 1000) {
		return "In 24 hrs";
	}
	$meridiem = "am";
	$minute = "00";
	$hour = $halfHour / 2;
	if ($hour == 0 || $hour == 0.5) {
		$hour = 12;
	}
	if ($hour >= 12) {
		$meridiem = "pm";
	}
	if ($hour >= 13) {
		$hour -= 12;
	}
	if ($halfHour % 2 != 0) {
		$minute = "30";
		$hour -= 0.5; // There's no explicit integer in PHP
	}
	$result = $hour . ":" . $minute . $meridiem;
	return $result;
}

// Used to find out which half hour time slots are free in a given space.
function debugSpaceArr($space) {
	$schedule = new Schedule($space);
	$numOfHalfHoursInDay = 48;
	$html = '';
	for ($i = 0; $i < $schedule->numSpacesInLibrary; $i++) {
		for ($j = 0; $j < $numOfHalfHoursInDay; $j++) {
			if (!$schedule->spaceArr[$i][$j]->hasReservation) {
				$html .= "Room $i Half Hour $j is free.<br>";
			}/*
			else {
				$html .= "Room $i Half Hour $j is taken by a reservation starting at " . 
				$schedule->spaceArr[$i][$j]->startDate . " and ending at " . $schedule->spaceArr[$i][$j]->endDate . "<br>";
			}*/
		}
	}
	
	return $html;
}
				
?>