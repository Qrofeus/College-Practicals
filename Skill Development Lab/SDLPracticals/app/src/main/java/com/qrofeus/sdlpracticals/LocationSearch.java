package com.qrofeus.sdlpracticals;

import androidx.fragment.app.FragmentActivity;

import android.location.Address;
import android.location.Geocoder;
import android.os.Bundle;
import android.widget.SearchView;
import android.widget.Toast;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;

import java.io.IOException;
import java.util.List;

public class LocationSearch extends FragmentActivity implements OnMapReadyCallback {

    GoogleMap map;
    SupportMapFragment fragment;
    SearchView searchView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        // Internet connection required
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_location_search);

        searchView = findViewById(R.id.searchBar);
        fragment = (SupportMapFragment) getSupportFragmentManager().findFragmentById(R.id.map_fragment);

        // On search
        searchView.setOnQueryTextListener(new SearchView.OnQueryTextListener() {
            @Override
            public boolean onQueryTextSubmit(String query) {
                // Clear all previous markers
                map.clear();

                String location = searchView.getQuery().toString();
                List<Address> addresses = null;

                if (!location.isEmpty()){
                    Geocoder geocoder = new Geocoder(LocationSearch.this);
                    try {
                        // Search for locations
                        addresses = geocoder.getFromLocationName(location, 5);
                    } catch (IOException e) {
                        e.printStackTrace();
                    }

                    if (addresses != null) {
                        for (Address address: addresses){
                            // Get latitude and longitude for all results and place markers
                            LatLng latLng = new LatLng(address.getLatitude(), address.getLongitude());
                            map.addMarker(new MarkerOptions().position(latLng).title(location));
                        }

                        // Update Map Camera for first result
                        map.animateCamera(CameraUpdateFactory.newLatLngZoom(new LatLng(addresses.get(0).getLatitude(), addresses.get(0).getLongitude()), 10.0f));
                    } else
                        Toast.makeText(LocationSearch.this, "No Locations found", Toast.LENGTH_SHORT).show();
                }
                return false;
            }

            @Override
            public boolean onQueryTextChange(String newText) {
                return false;
            }
        });

        fragment.getMapAsync(this);
    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        map = googleMap;
    }
}