<?php

/**
 * @file
 * souriau_cpt_sku.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function souriau_cpt_sku_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application|commerce_product|sku|form';
  $field_group->group_name = 'group_application';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'sku';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_sku_application',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Application',
    'weight' => '6',
  );
  $field_groups['group_application|commerce_product|sku|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_assembly|commerce_product|sku|form';
  $field_group->group_name = 'group_assembly';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'sku';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_sku_cable_type',
      1 => 'field_sku_connector_side_1',
      2 => 'field_sku_connector_side_2',
      3 => 'field_sku_ending_1',
      4 => 'field_sku_ending_2',
      5 => 'field_sku_gender_side_1',
      6 => 'field_sku_gender_side_2',
      7 => 'field_sku_layout_1',
      8 => 'field_sku_layout_2',
      9 => 'field_sku_overmolding_material',
      10 => 'field_sku_size_contact',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Assembly',
    'weight' => '3',
  );
  $field_groups['group_assembly|commerce_product|sku|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_backshell|commerce_product|sku|form';
  $field_group->group_name = 'group_backshell';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'sku';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_sku_backshell_angle',
      1 => 'field_sku_backshell_type',
      2 => 'field_sku_cable_diameter',
      3 => 'field_sku_cable_ending',
      4 => 'field_sku_mating_connector',
      5 => 'field_sku_cable_diam_max_inch',
      6 => 'field_sku_cable_diam_max_mm',
      7 => 'field_sku_cable_diam_min_inch',
      8 => 'field_sku_cable_diam_min_mm',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Backshell',
    'weight' => '4',
  );
  $field_groups['group_backshell|commerce_product|sku|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_connector|commerce_product|sku|form';
  $field_group->group_name = 'group_connector';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'sku';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_sku_body',
      1 => 'field_sku_connector_accessory_op',
      2 => 'field_sku_current_breaking_capac',
      3 => 'field_sku_module',
      4 => 'field_sku_number_cavity_05mm',
      5 => 'field_sku_number_cavity_07mm',
      6 => 'field_sku_number_cavity_09mm',
      7 => 'field_sku_number_cavity_100mm',
      8 => 'field_sku_number_cavity_10mm',
      9 => 'field_sku_number_cavity_120mm',
      10 => 'field_sku_number_cavity_15mm',
      11 => 'field_sku_number_cavity_16mm',
      12 => 'field_sku_number_cavity_20mm',
      13 => 'field_sku_number_cavity_25mm',
      14 => 'field_sku_number_cavity_30mm',
      15 => 'field_sku_number_cavity_36mm',
      16 => 'field_sku_number_cavity_50mm',
      17 => 'field_sku_number_cavity_70mm',
      18 => 'field_sku_number_cavity_coax_cts',
      19 => 'field_sku_number_cavity_elio',
      20 => 'field_sku_number_cavity_power_co',
      21 => 'field_sku_number_cavity_s00',
      22 => 'field_sku_number_cavity_s000',
      23 => 'field_sku_number_cavity_s0000',
      24 => 'field_sku_number_cavity_s10',
      25 => 'field_sku_number_cavity_s12',
      26 => 'field_sku_number_cavity_s12_mini',
      27 => 'field_sku_number_cavity_s14',
      28 => 'field_sku_number_cavity_s16',
      29 => 'field_sku_number_cavity_s16_mini',
      30 => 'field_sku_number_cavity_s2',
      31 => 'field_sku_number_cavity_s20',
      32 => 'field_sku_number_cavity_s22d',
      33 => 'field_sku_number_cavity_s26',
      34 => 'field_sku_number_cavity_s4',
      35 => 'field_sku_number_cavity_s6',
      36 => 'field_sku_number_cavity_s8_coax_',
      37 => 'field_sku_number_cavity_s8_power',
      38 => 'field_sku_number_cavity_s8_quadr',
      39 => 'field_sku_number_cavity_signal_c',
      40 => 'field_sku_plating_detail',
      41 => 'field_sku_with_ground_cavity',
      42 => 'field_sku_number_cavity_13mm',
      43 => 'field_sku_height_in',
      44 => 'field_sku_length_in',
      45 => 'field_sku_type_component',
      46 => 'field_sku_width_in',
      47 => 'field_sku_height_mm',
      48 => 'field_sku_length_mm',
      49 => 'field_sku_pcb_length_out_connect',
      50 => 'field_sku_weight_g',
      51 => 'field_sku_weight_plastics_g',
      52 => 'field_sku_width_mm',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Connector',
    'weight' => '2',
  );
  $field_groups['group_connector|commerce_product|sku|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|commerce_product|sku|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'sku';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_sku_active_part_technology',
      1 => 'field_sku_color_stripes_marking',
      2 => 'field_sku_contact_active_part_te',
      3 => 'field_sku_contact_compatibilitie',
      4 => 'field_sku_contact_packaging',
      5 => 'field_sku_contact_plating',
      6 => 'field_sku_contact_standard',
      7 => 'field_sku_ferrule_holder',
      8 => 'field_sku_ferrule_material',
      9 => 'field_sku_fiber_dimension',
      10 => 'field_sku_fiber_optic_contact_te',
      11 => 'field_sku_first_mate_last_break_',
      12 => 'field_sku_insert_material',
      13 => 'field_sku_insulation_grip',
      14 => 'field_sku_last_mate_first_break_',
      15 => 'field_sku_manufacturing_process',
      16 => 'field_sku_nut_material',
      17 => 'field_sku_pcb_diameter_mm',
      18 => 'field_sku_pcb_length',
      19 => 'field_sku_pcb_tail_angle',
      20 => 'field_sku_type_fiber',
      21 => 'field_sku_wire_acceptance_maxi_a',
      22 => 'field_sku_wire_acceptance_maxi_m',
      23 => 'field_sku_wire_acceptance_mini_a',
      24 => 'field_sku_wire_acceptance_mini_m',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Contact',
    'weight' => '1',
  );
  $field_groups['group_contact|commerce_product|sku|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cross_sell|commerce_product|sku|form';
  $field_group->group_name = 'group_cross_sell';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'sku';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_sku_complementary_part_num',
      1 => 'field_sku_recommended_part_num',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Cross sell',
    'weight' => '10',
  );
  $field_groups['group_cross_sell|commerce_product|sku|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|commerce_product|sku|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'sku';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'commerce_price',
      1 => 'field_sku_company',
      2 => 'field_samples_exception',
      3 => 'field_sku_description_sealing_le',
      4 => 'field_sku_packaging_quantity',
      5 => 'field_sku_product_series_code',
      6 => 'field_sku_suitable_for',
      7 => 'field_sku_type_accessory',
      8 => 'field_sku_type_tool',
      9 => 'field_view_exception',
      10 => 'title_field',
      11 => 'field_sku_samples_in_regions',
      12 => 'field_sku_view_in_regions',
      13 => 'field_sku_equivalent_part_number',
      14 => 'field_sku_alternate_search_key',
      15 => 'field_sku_note',
      16 => 'sku',
      17 => 'status',
    ),
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 1,
      ),
      'label' => 'General',
    ),
    'format_type' => 'tab',
    'label' => 'General',
    'weight' => '0',
  );
  $field_groups['group_general|commerce_product|sku|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|commerce_product|sku|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'sku';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_sku_3d_model',
      1 => 'field_sku_attachments',
      2 => 'field_sku_images',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Media',
    'weight' => '8',
  );
  $field_groups['group_media|commerce_product|sku|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_physic|commerce_product|sku|form';
  $field_group->group_name = 'group_physic';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'sku';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_sku_certification_csa',
      1 => 'field_sku_certification_iec',
      2 => 'field_sku_certification_ul',
      3 => 'field_sku_fire_smoke',
      4 => 'field_sku_flammability_rating',
      5 => 'field_sku_fluids',
      6 => 'field_sku_halogen_free',
      7 => 'field_sku_shielding',
      8 => 'field_sku_shock',
      9 => 'field_sku_test_current_ul',
      10 => 'field_sku_test_voltage_csa',
      11 => 'field_sku_test_voltage_iec',
      12 => 'field_sku_test_voltage_ul',
      13 => 'field_sku_touchproof',
      14 => 'field_sku_uv',
      15 => 'field_sku_vibrations',
      16 => 'field_sku_voltage_iec_v',
      17 => 'field_sku_voltage_ul_v',
      18 => 'field_sku_current_iec',
      19 => 'field_sku_current_ul',
      20 => 'field_sku_standard_csa',
      21 => 'field_sku_standard_iec',
      22 => 'field_sku_standard_ul',
      23 => 'field_sku_max_curr_cavity_s00',
      24 => 'field_sku_max_curr_cavity_s000',
      25 => 'field_sku_max_curr_cavity_s0000',
      26 => 'field_sku_maximum_current_cavity',
      27 => 'field_sku_s10_contact_rating',
      28 => 'field_sku_s12_contact_rating',
      29 => 'field_sku_s16_contact_rating',
      30 => 'field_sku_s20_contact_rating',
      31 => 'field_sku_s22_contact_rating',
      32 => 'field_sku_s26_contact_rating',
      33 => 'field_sku_s8_contact_rating',
      34 => 'field_sku_test_current_csa',
      35 => 'field_sku_test_current_iec',
      36 => 'field_sku_test_voltage_rating_21',
      37 => 'field_sku_test_voltage_rating_se',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Physic',
    'weight' => '5',
  );
  $field_groups['group_physic|commerce_product|sku|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_standards|commerce_product|sku|form';
  $field_group->group_name = 'group_standards';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'sku';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-standards field-group-tab',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Standards',
    'weight' => '9',
  );
  $field_groups['group_standards|commerce_product|sku|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_temporary_group|commerce_product|sku|form';
  $field_group->group_name = 'group_temporary_group';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'sku';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_sku_backshell_delivery',
      1 => 'field_sku_breaking_capability',
      2 => 'field_sku_contact_size_awg',
      3 => 'field_sku_contact_type',
      4 => 'field_sku_core_section_mm2',
      5 => 'field_sku_coupling',
      6 => 'field_sku_environmental',
      7 => 'field_sku_function',
      8 => 'field_sku_industrial',
      9 => 'field_sku_mating_cycles',
      10 => 'field_sku_plating',
      11 => 'field_sku_plug_type',
      12 => 'field_sku_receptacle_mount_type',
      13 => 'field_sku_salt_spray',
      14 => 'field_sku_shell_material',
      15 => 'field_sku_standard',
      16 => 'field_sku_temp_max_c',
      17 => 'field_sku_temp_max_f',
      18 => 'field_sku_temp_min_c',
      19 => 'field_sku_temp_min_f',
      20 => 'field_sku_voltage_v',
      21 => 'field_sku_vrms',
      22 => 'field_sku_wire_awg',
      23 => 'field_sku_connector_type',
      24 => 'field_sku_contact_delivery',
      25 => 'field_sku_number_of_contacts',
      26 => 'field_sku_sealing_level',
      27 => 'field_sku_shell_size',
      28 => 'field_sku_contact_gender',
      29 => 'field_sku_contact_size_mm',
      30 => 'field_sku_current_a',
      31 => 'field_sku_shell_continuity_mohm',
      32 => 'field_sku_layout',
      33 => 'field_sku_orientation',
      34 => 'field_sku_exemption',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-temporary-group field-group-tab',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Temporary Group',
    'weight' => '1',
  );
  $field_groups['group_temporary_group|commerce_product|sku|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_wire|commerce_product|sku|form';
  $field_group->group_name = 'group_wire';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'sku';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'children' => array(
      0 => 'field_sku_cable_length_m',
    ),
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'required_fields' => 1,
      ),
    ),
    'format_type' => 'tab',
    'label' => 'Wire',
    'weight' => '7',
  );
  $field_groups['group_wire|commerce_product|sku|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Application');
  t('Assembly');
  t('Backshell');
  t('Connector');
  t('Contact');
  t('Cross sell');
  t('General');
  t('Media');
  t('Physic');
  t('Standards');
  t('Temporary Group');
  t('Wire');

  return $field_groups;
}
