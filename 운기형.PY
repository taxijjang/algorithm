import json

in_file = json.dumps({"RouteID_00143bdd-0a6b-49ec-bb35-36593d303e77": {"station_code": "DLA3", "date_YYYY_MM_DD": "2018-07-27", "departure_time_utc": "16:02:10", "executor_capacity_cm3": 3313071.0, "route_score": "High", "stops": {"AD": {"lat": 34.099611, "lng": -118.283062, "type": "Dropoff", "zone_id": "P-12.3C"}, "AF": {"lat": 34.101587, "lng": -118.291125, "type": "Dropoff", "zone_id": "A-1.2D"}, "AG": {"lat": 34.089727, "lng": -118.28553, "type": "Dropoff", "zone_id": "A-2.1A"}, "BA": {"lat": 34.096132, "lng": -118.292869, "type": "Dropoff", "zone_id": "A-1.2C"}, "BE": {"lat": 34.098482, "lng": -118.286243, "type": "Dropoff", "zone_id": "P-13.3B"}, "BG": {"lat": 34.102251, "lng": -118.287403, "type": "Dropoff", "zone_id": "P-13.2A"}, "BP": {"lat": 34.095585, "lng": -118.28179, "type": "Dropoff", "zone_id": "P-13.2C"}, "BT": {"lat": 34.101474, "lng": -118.289609, "type": "Dropoff", "zone_id": "A-1.1D"}, "BY": {"lat": 34.091721, "lng": -118.284539, "type": "Dropoff", "zone_id": "A-1.1A"}, "BZ": {"lat": 34.098179, "lng": -118.281075, "type": "Dropoff", "zone_id": "P-13.1C"}, "CA": {"lat": 34.100562, "lng": -118.290796, "type": "Dropoff", "zone_id": "A-1.2D"}, "CG": {"lat": 34.093119, "lng": -118.291761, "type": "Dropoff", "zone_id": "A-1.1B"}, "CK": {"lat": 34.095794, "lng": -118.279086, "type": "Dropoff", "zone_id": "P-13.1D"}, "CM": {"lat": 34.097235, "lng": -118.276636, "type": "Dropoff", "zone_id": "P-12.2D"}, "CO": {"lat": 34.1018, "lng": -118.286716, "type": "Dropoff", "zone_id": "P-13.2A"}, "CP": {"lat": 34.096991, "lng": -118.290254, "type": "Dropoff", "zone_id": "A-1.2C"}, "CW": {"lat": 34.093458, "lng": -118.284798, "type": "Dropoff", "zone_id": "A-1.2A"}, "DJ": {"lat": 34.09039, "lng": -118.293879, "type": "Dropoff", "zone_id": "A-1.1C"}, "DL": {"lat": 34.094262, "lng": -118.283726, "type": "Dropoff", "zone_id": "A-1.2A"}, "DN": {"lat": 34.096991, "lng": -118.290254, "type": "Dropoff", "zone_id": "A-1.2C"}, "DQ": {"lat": 34.097468, "lng": -118.291886, "type": "Dropoff", "zone_id": "A-1.2C"}, "EC": {"lat": 34.100006, "lng": -118.282101, "type": "Dropoff", "zone_id": "P-12.3C"}, "EH": {"lat": 34.098182, "lng": -118.279915, "type": "Dropoff", "zone_id": "P-12.3D"}, "EO": {"lat": 34.096917, "lng": -118.285385, "type": "Dropoff", "zone_id": "P-13.2A"}, "EX": {"lat": 34.09914, "lng": -118.282492, "type": "Dropoff", "zone_id": "P-12.3C"}, "EY": {"lat": 34.097596, "lng": -118.279776, "type": "Dropoff", "zone_id": "P-13.2C"}, "FF": {"lat": 34.096966, "lng": -118.278668, "type": "Dropoff", "zone_id": "P-13.1D"}, "FH": {"lat": 34.093868, "lng": -118.283305, "type": "Dropoff", "zone_id": "A-1.2A"}}}})
actual_routes = json.loads(in_file)

# "RouteID_<hex-hash>"
first_depth_key = list(actual_routes.keys())[0]
print(f"RouteID : {first_depth_key}")
print("---------------------------------------------------")
# "RouteID_<hex-hash>" - value
second_depth_value = actual_routes.get(first_depth_key)
## version1 - hard-coding
second_depth_value.get('station_code')
second_depth_value.get('date_YYYY_MM_DD')
second_depth_value.get('departure_time_utc')
second_depth_value.get('executor_capacity_cm3')
second_depth_value.get('route_score')
second_depth_value.get('stops')
## version2 - for
second_depth_keys = list(actual_routes.get(first_depth_key).keys())
for second_depth_key in second_depth_keys:
    print(f"{second_depth_key} : {second_depth_value.get(second_depth_key)}")
print("---------------------------------------------------")
# third_depth_value
third_depth_value = second_depth_value.get('stops')
print(f"thrid_depth_value : {third_depth_value}")
print("---------------------------------------------------")
# third_depth_keys - stops
third_depth_keys = list(second_depth_value.get('stops').keys())
print(f"thrid_depth_keys : {third_depth_keys}")
print("---------------------------------------------------")

# fourth_depth_value
print("fourth_depth_value")
for third_depth_key in third_depth_keys:
    print(f"{third_depth_key} : {third_depth_value.get(third_depth_key)}")
print("---------------------------------------------------")



